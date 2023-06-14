<template>
  <div class="flex h:100% gap:16px flex:nowrap overflow-y:auto">
    <BagElement v-for="bag in bags" :key="bag.name" :bag="bag" @click="$emit('chooseBag', bag)" />
  </div>
</template>

<script setup lang="ts">
import { toRefs } from 'vue';

import type { Potion } from '@/common/useWebSocket';

import BagElement from './BagElement.vue';

//#region Props and Emit
interface BagPanelProps {
  bags: Potion[];
}
const props = defineProps<BagPanelProps>();
const { bags } = toRefs(props);

defineEmits(['chooseBag']);
//#endregion
</script>
