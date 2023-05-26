<template>
  <n-layout-content>
    <div class="w:75% margin:2em|auto">
      <div class="grid-cols:2 h:100% align-items:center">
        <div>
          <div class="font:3em font-weight:900">Project 3 | Pokémon</div>
          <div class="font:1.2em mt:.5em line-height:1.75em font-weight:500 f:#aaa">
            歡迎你進入寶可夢的世界，<br />
            在這裡你將和全球頂尖的訓練家們展開刺激的對決。<br />
            每一次的勝利，<br />
            都將讓你與成為寶可夢大師的夢想更近一步。<br /><br />
            你，準備好證明自己，<br />
            成為最強大的寶可夢訓練家了嗎？
          </div>
          <div class="mt:6em flex gap:16px">
            <n-button
              class="p:1em|2em font:2em font-weight:500"
              type="primary"
              @click="$router.push({ name: 'Game' })"
            >
              <template #icon>
                <n-icon class="mr:16px" size="32px">
                  <PokemonBallIcon />
                </n-icon>
              </template>
              Play
            </n-button>
            <n-button
              type="primary"
              class="p:1em|2em font:2em font-weight:500"
              tag="a"
              href="https://github.com/LiaoAnn/oop-pokemon"
              target="_blank"
              ghost
            >
              <template #icon>
                <n-icon class="mr:16px" size="32px">
                  <GithubIcon />
                </n-icon>
              </template>
              Github
            </n-button>
          </div>
        </div>
        <div
          :class="`bg:url('${HomeImage}') height:600px background-size:125% bg:no-repeat background-position:0%|50%`"
        ></div>
      </div>
    </div>
  </n-layout-content>
</template>

<script setup lang="ts">
import { NButton, NIcon, NLayoutContent } from 'naive-ui';

import HomeImage from '@/assets/home-image.jpg';
import GithubIcon from '@/components/icons/GithubIcon.vue';
import PokemonBallIcon from '@/components/icons/PokemonBallIcon.vue';
</script>
