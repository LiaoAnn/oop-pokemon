<template>
  <div :class="`cursor:pointer p:8px flex flex:col justify-content:center align-items:center`">
    <div :class="`h:100% w:100px bg:url('${PotionImg}') bg:no-repeat background-size:100%`"></div>
    <div>
      {{ bag.name }}
    </div>
    <div class="fonnt:#ddd">
      {{ bag.points }}
    </div>
  </div>
</template>

<script setup lang="ts">
import { toRefs } from 'vue';

import PotionImg from '@/assets/potion.png';
import type { Potion } from '@/common/useWebSocket';

//#region Props
interface BagElementProps {
  bag: Potion;
}
const props = defineProps<BagElementProps>();
const { bag } = toRefs(props);
//#endregion
</script>
