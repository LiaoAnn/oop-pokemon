# Backend development environment setup
This project using Cmake to build. make sure you have Cmake installed on your machine. You can find the installation guide [here](https://cmake.org/install/).

## Visual Studio 2022
This file provides an overview of the necessary steps for setting up the environment to compile WebSocket++ under normal circumstances.

### Recommended IDE Setup

VS2022 (v143) is the only version that has been tested and confirmed to be compatible with the latest versions of Boost (1.82.0) and WebSocket++ (0.8.2). Please make sure to use the correct versions accordingly.

And the Cmake version is dependent on the VS version. The Cmake version used in this project is 3.21.3. This is built-in in VS2022. If you are using other versions of VS, please make sure to install the correct version of Cmake.

### Installation

#### Boost

1. You can download the source code from [Boost](https://www.boost.org/) and compile it yourself, but it is recommended to download a pre-compiled version from [Sourceforge](https://sourceforge.net/projects/boost/files/boost-binaries/) for easier installation.
2. After downloading, install Boost to a specified location based on your needs.
3. Run bootstrap.bat to generate b2.exe, and then run b2.exe.
4. The stage folder will be generated in the directory, which is the directory that the linker needs.

#### WebSocket++

1. Download the source code files from the [WebSocket++](https://docs.websocketpp.org/) official website or [GitHub](https://github.com/zaphoyd/websocketpp/).
2. Unzip the files to the specified location.

#### IDE setup

1. Add the Boost and WebSocket++ directories to the include directory of the project cmakelists.txt file by following command.
    ```cmake
    set(Boost_INCLUDE_DIR
	    # Add your own Boost include path here
    )
    set(Boost_LIBRARY_DIR 
	    # Add your own Boost library path here
    )
    set(WebSocketpp
	    # Add your own WebSocketpp include path here
    )   
    ```

## docker
If you don't want to install the dependencies on your machine, you can use docker to build and run the project.

1. Install docker on your machine. You can find the installation guide [here](https://docs.docker.com/get-docker/).
2. Build and run the docker image

    The docker file is already included in the project. You can use the following command to build the docker image.
    ```bash
    docker build -t <image_name> .
    ```
    and run the docker image with the following command
    ```bash
    docker run -p 9002:9002 <image_name>
    ```

Also, that is no need to install WebSocket++ and boost on your machine if using docker.

### Note
Please make sure your test file is in the same directory as the *.exe file. Otherwise, the program will not be able to find the file.