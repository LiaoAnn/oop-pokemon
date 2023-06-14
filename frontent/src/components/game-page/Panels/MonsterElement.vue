<template>
  <div
    :class="`bg:${
      monster.name == currMonsterName ? '#333' : 'white'
    } cursor:pointer p:8px flex flex:col justify-content:center align-items:center`"
  >
    <div :class="`h:100% w:150px bg:url('${MyMonster}') bg:no-repeat background-size:100%`"></div>
    <div>
      {{ monster.name }}
    </div>
  </div>
</template>

<script setup lang="ts">
import { toRefs } from 'vue';

import MyMonster from '@/assets/my-monster.png';
import type { Monster } from '@/common/useWebSocket';

//#region Props
interface MonsterElementProps {
  monster: Monster;
  currMonsterName: string;
}
const props = defineProps<MonsterElementProps>();
const { monster } = toRefs(props);
//#endregion
</script>
