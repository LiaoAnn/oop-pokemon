<template>
  <div class="flex h:100% gap:16px flex:nowrap overflow-y:auto">
    <MonsterElement
      v-for="monster in monsters"
      :key="monster.name"
      :curr-monster-name="currMonsterName"
      :monster="monster"
      @click="monster.name != currMonsterName && $emit('chooseMonster', monster)"
    />
  </div>
</template>

<script setup lang="ts">
import { toRefs } from 'vue';

import type { Monster } from '@/common/useWebSocket';

import MonsterElement from './MonsterElement.vue';

//#region Props and Emit
interface MonsterPanelProps {
  monsters: Monster[];
  currMonsterName: string;
}
const props = defineProps<MonsterPanelProps>();
const { monsters } = toRefs(props);

defineEmits(['chooseMonster']);
//#endregion
</script>
