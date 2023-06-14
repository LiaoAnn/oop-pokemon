export enum SendMsgType {
  Init = 'init',
  LoadMonster = 'load_monster',
  LoadMove = 'load_move',
  LoadGameData = 'load_game_data',
  LoadCase = 'load_case'
}

export enum ReceiveMsgType {
  Init = 'init',
  LoadCase = 'load_case'
}

export interface SendMsg {
  type: SendMsgType;
  file?: string;
}

export interface ReceiveMsg {
  type: ReceiveMsgType;
  success: boolean;
  battle_log: string[];
  myMonsters: string[];
  otherMonsters: string[];
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
