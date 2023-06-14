<template>
  <div
    class="grid h:100% gap:8px p:4|8 grid-template-cols:repeat(2,1fr) grid-template-rows:repeat(2,1fr) align-items:center!"
  >
    <MoveElement
      v-for="move in moves"
      :key="move.name"
      :move="move"
      @click="$emit('chooseMove', move)"
    />
  </div>
</template>

<script setup lang="ts">
import { toRefs } from 'vue';

import type { Move } from '@/common/useWebSocket';

import MoveElement from './MoveElement.vue';

//#region Props and Emit
interface MovePanelProps {
  moves: Move[];
}
const props = defineProps<MovePanelProps>();
const { moves } = toRefs(props);

defineEmits(['chooseMove']);
//#endregion
</script>
