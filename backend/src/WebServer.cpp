#include "WebServer.h"


WebServer::WebServer(string root_directory, int port)
{
	this->port = port;
	this->root_directory = root_directory;
}

string WebServer::get_file_content(const string& file_path) 
{
	ifstream file(file_path);
	if (file) 
	{
		string content((istreambuf_iterator<char>(file)),
			istreambuf_iterator<char>());
		return content;
	}
	return "";
}

string WebServer::get_content_type(const string& file_path) 
{
	static const unordered_map<string, string> contentTypes = {
		{ ".html", "text/html" },
		{ ".css", "text/css" },
		{ ".js", "application/javascript" },
		{ ".jpg", "image/jpeg" },
		{ ".png", "image/png" },
		{ ".ico", "image/x-icon" },
		{ ".svg", "image/svg+xml" }
	};

	size_t dotPos = file_path.rfind('.');
	if (dotPos != string::npos) 
	{
		string extension = file_path.substr(dotPos);
		auto it = contentTypes.find(extension);
		if (it != contentTypes.end()) 
		{
			return it->second;
		}
	}

	return "application/octet-stream";
}

void WebServer::handle_request(const http::request<http::string_body>& request, http::response<http::string_body>& response) 
{
	string path = request.target();
	string file_path = root_directory + path;
	// 嘗試讀取檔案內容
	string file_content = get_file_content(file_path);

	if (!file_content.empty())
	{
		// 文件存在，設置回應的内容和Content-Type
		response.body() = file_content;
		response.set(http::field::content_type, get_content_type(file_path));
		response.result(http::status::ok);
	}
	else 
	{
		// 文件不存在，返回404 Not Found
		string default_file = root_directory + "/index.html";
		string default_content = get_file_content(default_file);

		if (!default_content.empty())
		{
			response.body() = default_content;
			response.set(http::field::content_type, get_content_type(default_file));
			response.result(http::status::ok);
		}
		else 
		{
			response.result(http::status::not_found);
		}
	}
}

void WebServer::run()
{
	boost::asio::io_context io;
	tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), port));
	while (true) 
	{
		tcp::socket socket(io);
		acceptor.accept(socket);
		http::request<http::string_body> request;
		boost::beast::flat_buffer buffer; 
		http::read(socket, buffer, request);
		http::response<http::string_body> response;
		handle_request(request, response);
		http::write(socket, response);
	}
}

