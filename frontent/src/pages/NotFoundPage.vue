<template>
  <div
    :class="`rel bg:${darkSecondaryColor} height:100vh overflow:hidden flex align-items:center justify-content:center`"
  >
    <div :class="`f:${primaryColor} font:8em font-weight:900 user-select:none`">
      404 Not Found...
    </div>
    <n-icon class="abs top:-10% right:-10% transform:rotate(-35deg)" size="500px">
      <NormalBallIcon />
    </n-icon>
    <n-icon class="abs bottom:30% left:0 transform:rotate(35deg)|translateY(50%)" size="300px">
      <UltraBallIcon />
    </n-icon>
  </div>
</template>

<script setup lang="ts">
import { NIcon } from 'naive-ui';

import useTheme from '@/common/useTheme';
import NormalBallIcon from '@/components/icons/NormalBallIcon.vue';
import UltraBallIcon from '@/components/icons/UltraBallIcon.vue';
const { darkSecondaryColor, primaryColor } = useTheme();
</script>
