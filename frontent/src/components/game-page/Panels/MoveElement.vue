<template>
  <n-layout class="cursor:pointer h:100% p:4">
    <n-layout-header> {{ move.attribute }} | {{ move.name }} </n-layout-header>

    <n-layout-content> Times: {{ move.currentPP }} / {{ move.totalPP }} </n-layout-content>

    <n-layout-content> Power: {{ move.power }} </n-layout-content>
  </n-layout>
</template>

<script setup lang="ts">
import { NLayout, NLayoutContent, NLayoutHeader } from 'naive-ui';
import { toRefs } from 'vue';

import type { Move } from '@/common/useWebSocket';

//#region Props
interface MoveElementProps {
  move: Move;
}
const props = defineProps<MoveElementProps>();
const { move } = toRefs(props);
//#endregion
</script>
