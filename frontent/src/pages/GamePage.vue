<template>
  <n-layout-content>
    <div ref="gameDivRef" class="w:80% h:max(calc(100vh-56px),800px) margin:0|auto p:1em|0">
      <div class="flex flex:col h:100%">
        <div
          :class="`flex-grow:3 bg:url('${BattleBackground}') height:600px background-size:100% bg:no-repeat background-position:0%|100%`"
        ></div>
        <div
          id="control-panel"
          class="flex-grow:1 grid grid-template-cols:repeat(4,1fr) min-h:175px"
        ></div>
      </div>
    </div>
  </n-layout-content>
</template>

<script setup lang="ts">
import { NLayoutContent, useDialog } from 'naive-ui';
import { h, ref } from 'vue';

import BattleBackground from '@/assets/battle-background.png';
import type { ReceiveMsg } from '@/common/useWebSocket';
import { ReceiveMsgType, SendMsgType, useWebSocket } from '@/common/useWebSocket';
import TestFileSelectDialog from '@/components/game-page/TestFileSelectDialog.vue';

//#region WebSocket
const onMsg = (e: MessageEvent) => {
  const { data } = e;
  const msg = JSON.parse(data) as ReceiveMsg;

  switch (msg.type) {
    case ReceiveMsgType.LoadCase:
      console.log(msg);
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

const gameDivRef = ref<HTMLElement | null>(null);
const dialog = useDialog();

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
