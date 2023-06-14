export enum SendMsgType {
  Init = 'init',
  LoadMonster = 'load_monster',
  LoadMove = 'load_move',
  LoadGameData = 'load_game_data',
  LoadCase = 'load_case',
  SelectMonster = 'select_monster',
  InitAttack = 'init_attack',
  Attack = 'attack',
  InitTeam = 'init_team',
  InitBag = 'init_bag',
  RunAway = 'run_away',
  Bag = 'bag'
}

export enum ReceiveMsgType {
  Init = 'init',
  LoadCase = 'load_case',
  InitAttack = 'init_attack',
  InitTeam = 'init_team',
  InitBag = 'init_bag',
  Attack = 'attack',
  RequirementSelectMonster = 'requirement_select_monster',
  SelectMonster = 'select_monster',
  OtherSelectMonster = 'other_select_monster',
  Win = 'win',
  Lose = 'lose',
  Bag = 'bag'
}

export interface SendMsg {
  type: SendMsgType;
  file?: string;
  monster?: string;
  move?: string;
  item?: string;
}

export interface ReceiveMsg {
  type: ReceiveMsgType;
  success: boolean;
  battle_log?: string[];
  myMonster?: Monster;
  myMonsters?: Monster[];
  otherMonster?: Monster;
  otherMonsters?: Monster[];
  bag?: Potion[];
  attackFirst?: string;
}

export interface Potion {
  name: string;
  points: number;
}

export interface Move {
  accuracy: number;
  attackKind: string;
  attribute: string;
  currentPP: number;
  effect: {
    leftRound: number;
    name: string;
    power: number;
    type: string;
  };
  name: string;
  power: number;
  totalPP: number;
}

export interface Monster {
  attack: number;
  defense: number;
  health: number;
  maxHealth: number;
  moves: Move[];
  name: string;
  s_attack: number;
  s_defense: number;
  speed: number;
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
