<template>
  <n-layout-content>
    <div ref="gameDivRef" class="w:80% h:max(calc(100vh-56px),800px) margin:0|auto p:1em|0">
      <div class="flex flex:col h:100%">
        <div
          :class="`rel flex-grow:3 bg:url('${BattleBackground}') height:600px background-size:100% bg:no-repeat background-position:0%|100%`"
        >
          <img v-if="initSuccess" :src="MyMonster" class="abs h:450px w:450px bottom:-5% left:5%" />
          <img
            v-if="initSuccess"
            :src="OthersMonster"
            class="abs h:300px w:300px top:10% right:12%"
          />
          <div v-if="myMonster" :class="`abs w:500px h:75px top:20% bg:${darkSecondaryColor}`">
            <div class="flex color:white p:8px gap:8px">
              <div>
                {{ myMonster?.name }}
              </div>
              <div class="bg:#ddd w:100%">
                <div
                  :class="`w:${myMonster!.health / myMonster!.maxHealth * 100}% h:100% bg:#900`"
                ></div>
              </div>
              <div>{{ myMonster?.health }}/{{ myMonster?.maxHealth }}</div>
            </div>
          </div>
          <div
            v-if="othersMonster"
            :class="`abs w:500px right:0 h:75px top:60% bg:${darkSecondaryColor}`"
          >
            <div class="flex color:white p:8px gap:8px">
              <div>
                {{ othersMonster?.name }}
              </div>
              <div class="bg:#ddd w:100%">
                <div
                  :class="`w:${othersMonster!.health / othersMonster!.maxHealth * 100}% h:100% bg:#900`"
                ></div>
              </div>
              <div>{{ othersMonster?.health }}/{{ othersMonster?.maxHealth }}</div>
            </div>
          </div>
        </div>
        <div id="control-panel" class="flex-grow:1 grid grid-template-cols:repeat(4,1fr) h:175px">
          <div v-if="initSuccess" class="h:100% overflow:auto">
            <div v-for="log in battleLog" :key="log">
              {{ log }}
            </div>
          </div>
          <div v-if="initSuccess" class="grid-col-span:2">
            <MovePanel
              v-if="currPanel == Panels.Move && myMonster"
              :moves="myMonster?.moves"
              @choose-move="ChooseMove"
            />
            <MonsterPanel
              v-if="currPanel == Panels.Monster"
              :monsters="myMonsters"
              :curr-monster-name="myMonster?.name!"
              @choose-monster="ChooseMonster"
            />
            <BagPanel v-if="currPanel == Panels.Bag" :bags="myBag" @choose-bag="ChooseBag" />
          </div>

          <div
            v-if="initSuccess"
            class="grid p:12px gap:16px grid-template-cols:repeat(2,1fr) grid-template-rows:repeat(2,1fr)"
          >
            <div
              v-for="panel in Object.values(Panels)"
              :key="panel"
              class="flex h:100% justify-content:center cursor:pointer align-items:center bg:white"
              @click="SwitchPanel(panel)"
            >
              {{ panel }}
            </div>
          </div>
        </div>
      </div>
    </div>
  </n-layout-content>
</template>

<script setup lang="ts">
import { NLayoutContent, useDialog } from 'naive-ui';
import { h, ref } from 'vue';
import { useRouter } from 'vue-router';

import mp3 from '@/assets/battle.mp3';
import BattleBackground from '@/assets/battle-background.png';
import MyMonster from '@/assets/my-monster.png';
import OthersMonster from '@/assets/others-monster.png';
import useTheme from '@/common/useTheme';
import type { Monster, Move, Potion, ReceiveMsg } from '@/common/useWebSocket';
import { ReceiveMsgType, SendMsgType, useWebSocket } from '@/common/useWebSocket';
import BagPanel from '@/components/game-page/Panels/BagPanel.vue';
import MonsterPanel from '@/components/game-page/Panels/MonsterPanel.vue';
import MovePanel from '@/components/game-page/Panels/MovePanel.vue';
import TestFileSelectDialog from '@/components/game-page/TestFileSelectDialog.vue';

const initSuccess = ref(false);
const gameDivRef = ref<HTMLElement | null>(null);
const dialog = useDialog();
const battleLog = ref<string[]>([]);
const myMonster = ref<Monster | null>(null);
const myMonsters = ref<Monster[]>([]);
const othersMonster = ref<Monster | null>(null);
const othersMonsters = ref<Monster[]>([]);
const myBag = ref<Potion[]>([]);
const { darkSecondaryColor } = useTheme();
const router = useRouter();
const battleBGM = new Audio(mp3);
battleBGM.loop = true;

enum Panels {
  Move = 'Move',
  Monster = 'Monster',
  Bag = 'Bag',
  Run = 'Run'
}
const currPanel = ref<Panels | null>(null);

const ChooseMove = (move: Move) => {
  sendMsg({
    type: SendMsgType.Attack,
    move: move.name
  });
};

const ChooseMonster = (monster: Monster) => {
  sendMsg({
    type: SendMsgType.SelectMonster,
    monster: monster.name
  });
};

const ChooseBag = (bag: Potion) => {
  sendMsg({
    type: SendMsgType.Bag,
    monster: myMonster.value?.name,
    item: bag.name
  });
};

const SwitchPanel = (panel: Panels) => {
  switch (panel) {
    case Panels.Move:
      sendMsg({
        type: SendMsgType.InitAttack
      });
      break;
    case Panels.Monster:
      sendMsg({
        type: SendMsgType.InitTeam
      });
      break;
    case Panels.Bag:
      sendMsg({
        type: SendMsgType.InitBag
      });
      break;
    case Panels.Run:
      sendMsg({
        type: SendMsgType.RunAway
      });
      break;
  }
};

//#region WebSocket
const onMsg = (e: MessageEvent) => {
  const { data } = e;
  const msg = JSON.parse(data) as ReceiveMsg;

  switch (msg.type) {
    case ReceiveMsgType.LoadCase:
      battleLog.value = msg.battle_log!.reverse();
      initSuccess.value = true;
      myMonsters.value = msg.myMonsters!;
      othersMonsters.value = msg.otherMonsters!;

      sendMsg({
        type: SendMsgType.InitAttack
      });
      break;
    case ReceiveMsgType.InitAttack:
      battleLog.value = msg.battle_log!.reverse();
      myMonster.value = msg.myMonster!;
      othersMonster.value = msg.otherMonster!;
      currPanel.value = Panels.Move;
      break;
    case ReceiveMsgType.InitBag:
      myBag.value = msg.bag!;
      currPanel.value = Panels.Bag;
      break;
    case ReceiveMsgType.InitTeam:
      battleLog.value = msg.battle_log!.reverse();
      myMonsters.value = msg.myMonsters!;
      currPanel.value = Panels.Monster;
      break;
    case ReceiveMsgType.Attack:
      battleLog.value = msg.battle_log!.reverse();
      if (msg.attackFirst! == 'other') {
        myMonster.value = msg.myMonster!;
        setTimeout(() => {
          othersMonster.value = msg.otherMonster!;
        }, 1000);
      } else {
        othersMonster.value = msg.otherMonster!;
        setTimeout(() => {
          myMonster.value = msg.myMonster!;
        }, 1000);
      }
      break;
    case ReceiveMsgType.RequirementSelectMonster:
      currPanel.value = Panels.Monster;
      break;
    case ReceiveMsgType.SelectMonster:
      battleLog.value = msg.battle_log!.reverse();
      myMonster.value = msg.myMonster!;
      othersMonster.value = msg.otherMonster!;
      othersMonsters.value = msg.otherMonsters!;
      currPanel.value = Panels.Move;
      break;
    case ReceiveMsgType.OtherSelectMonster:
      othersMonster.value = msg.otherMonster!;
      break;
    case ReceiveMsgType.Win:
      dialog.success({
        title: '遊戲結束',
        content: '我方獲勝！',
        positiveText: '在玩一局',
        negativeText: '回首頁',
        onPositiveClick: () => {
          location.reload();
        },
        onNegativeClick() {
          router.push('/');
        }
      });
      break;
    case ReceiveMsgType.Lose:
      dialog.success({
        title: '遊戲結束',
        content: '對方獲勝！',
        positiveText: '在玩一局',
        negativeText: '回首頁',
        onPositiveClick: () => {
          location.reload();
        },
        onNegativeClick() {
          router.push('/');
        }
      });
      break;
    case ReceiveMsgType.Bag:
      battleLog.value = msg.battle_log!.reverse();
      myMonster.value = msg.myMonster!;
      othersMonster.value = msg.otherMonster!;
      break;
    default:
      break;
  }
};
const { openWs, sendMsg } = useWebSocket(onMsg);
(async () => {
  await openWs();
  sendMsg({ type: SendMsgType.Init });
})();
//#endregion

const openTestFileSelectDialog = () => {
  const testFileSelectDialog = dialog.info({
    title: '選取測試檔案',
    content: () =>
      h(TestFileSelectDialog, {
        onSubmit: (value) => {
          const { Monster, Move, GameData, Case } = value;
          console.log(Monster, Move, GameData, Case);
          sendMsg({
            type: SendMsgType.LoadMonster,
            file: Monster
          });
          sendMsg({
            type: SendMsgType.LoadMove,
            file: Move
          });
          sendMsg({
            type: SendMsgType.LoadGameData,
            file: GameData
          });
          sendMsg({
            type: SendMsgType.LoadCase,
            file: Case
          });
          testFileSelectDialog.destroy();
          battleBGM.play();
        }
      })
  });
};

openTestFileSelectDialog();
</script>

<style scoped>
#control-panel {
  background: rgb(32, 166, 56);
  background: linear-gradient(
    90deg,
    rgba(32, 166, 56, 1) 0%,
    rgba(78, 186, 79, 1) 12%,
    rgba(125, 206, 102, 1) 23%,
    rgba(85, 195, 84, 1) 33%,
    rgba(19, 138, 59, 1) 59%,
    rgba(101, 202, 100, 1) 65%,
    rgba(89, 202, 91, 1) 100%
  );
}
</style>
