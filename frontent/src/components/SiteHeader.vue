<template>
  <n-layout-header>
    <div :class="`p:.5em|0 bg:${darkPrimaryColor}`">
      <div
        class="w:80% flex align-items:center justify-content:space-between margin:0|auto height:3em"
      >
        <div class="flex align-items:center gap:48px">
          <router-link to="/">
            <n-icon :class="`height:${logoHeight}px width:${logoWidth}px`">
              <PokemonLogo :height="logoHeight" :width="logoWidth" />
            </n-icon>
          </router-link>
          <n-menu
            v-model:value="currMenuValue"
            :options="menuOptions"
            mode="horizontal"
            @update:value="currMenuValue = $event"
          />
        </div>
      </div>
    </div>
  </n-layout-header>
</template>

<script setup lang="ts">
import type { MenuOption } from 'naive-ui';
import { NIcon, NLayoutHeader, NMenu } from 'naive-ui';
import { computed, h } from 'vue';
import { RouterLink } from 'vue-router';
import { useRoute } from 'vue-router';

import useTheme from '@/common/useTheme';

import PokemonLogo from './icons/PokemonLogo.vue';

const route = useRoute();
const classStr = 'display:block padding:0|.5em color:inherit text-decoration:none';
const currMenuValue = computed(() => {
  const { name } = route;
  return name?.toString() || 'home';
});
const { darkPrimaryColor } = useTheme();
const logoHeight = 32;
const logoWidth = 100;
const menuOptions: MenuOption[] = [
  {
    label: () =>
      h(
        RouterLink,
        {
          to: '/',
          class: classStr
        },
        'Home'
      ),
    name: 'Home',
    key: 'Home'
  },
  {
    label: () =>
      h(
        RouterLink,
        {
          to: '/game',
          class: classStr
        },
        'Game'
      ),
    name: 'Game',
    key: 'Game'
  }
];
</script>
