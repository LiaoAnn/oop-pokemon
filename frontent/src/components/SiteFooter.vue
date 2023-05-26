<template>
  <n-layout-footer>
    <div :class="`bg:${darkPrimaryColor} p:2em|0`">
      <div class="w:80% margin:0|auto grid-cols:2 justify-content:center">
        <div class="flex gap:16px align-items:center">
          <n-icon :class="`height:${logoHeight} width:${logoWidth}`">
            <PokemonLogo :width="logoWidth" :height="logoHeight" />
          </n-icon>
          <div :class="`f:${secondaryColor} font:2em font-weight:500`">Project 3 | Pokémon</div>
        </div>
        <div>
          <div :class="`f:${secondaryColor} font-weight:400 font:1em`">組員</div>

          <div class="flex align-items:center">
            <n-icon size="1.5em">
              <MasterBallIcon />
            </n-icon>
            <div class="f:white font:1.5em p:4px">廖廷安</div>
            <div :class="`f:${secondaryColor} font:1.5em p:4px`">| B11130237</div>
          </div>

          <div class="flex align-items:center">
            <n-icon size="1.5em">
              <UltraBallIcon />
            </n-icon>
            <div class="f:white font:1.5em p:4px">劉耀恩</div>
            <div :class="`f:${secondaryColor} font:1.5em p:4px`">| B11115039</div>
          </div>

          <div class="flex align-items:center">
            <n-icon size="1.5em">
              <UltraBallIcon />
            </n-icon>
            <div class="f:white font:1.5em p:4px">劉沛安</div>
            <div :class="`f:${secondaryColor} font:1.5em p:4px`">| B11115034</div>
          </div>

          <div class="flex align-items:center">
            <n-icon size="1.5em">
              <NormalBallIcon />
            </n-icon>
            <div class="f:white font:1.5em p:4px">譚秉家</div>
            <div :class="`f:${secondaryColor} font:1.5em p:4px`">| B11115001</div>
          </div>
        </div>
      </div>

      <div class="text-align:center f:white mt:16px">Made with ❤️ by Group 23</div>
    </div>
  </n-layout-footer>
</template>

<script setup lang="ts">
import { NIcon, NLayoutFooter } from 'naive-ui';

import useTheme from '@/common/useTheme';

import MasterBallIcon from './icons/MasterBallIcon.vue';
import NormalBallIcon from './icons/NormalBallIcon.vue';
import PokemonLogo from './icons/PokemonLogo.vue';
import UltraBallIcon from './icons/UltraBallIcon.vue';

const { secondaryColor, darkPrimaryColor } = useTheme();
const logoHeight = 64;
const logoWidth = 200;
</script>
