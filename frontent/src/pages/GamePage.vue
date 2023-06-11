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
import { NLayoutContent } from 'naive-ui';
import { ref } from 'vue';

import BattleBackground from '@/assets/battle-background.png';

const gameDivRef = ref<HTMLElement | null>(null);
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
