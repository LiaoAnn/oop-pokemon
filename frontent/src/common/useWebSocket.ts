export enum SendMsgType {
  Init = 'init',
  LoadFile = 'loadFile'
}

export enum ReceiveMsgType {}

export interface SendMsg {
  type: SendMsgType;
}

export interface ReceiveMsg {
  type: ReceiveMsgType;
  success?: boolean;
}

export function useWebSocket(onMsgCallback: (e: MessageEvent) => void) {
  const ws = new WebSocket('ws://localhost:9002');
  const openWs = async () => {
    return new Promise((resolve, reject) => {
      if (ws.readyState === WebSocket.OPEN) {
        resolve(ws);
      }
      ws.onopen = () => {
        resolve(ws);
      };
      ws.onerror = (e) => {
        reject(e);
      };
    });
  };
  const sendMsg = async (msg: SendMsg) => {
    await openWs();
    ws.send(JSON.stringify(msg));
  };
  ws.onmessage = onMsgCallback;

  return { openWs, sendMsg };
}
