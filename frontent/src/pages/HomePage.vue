<template>
  <n-layout-content>
    <div class="w:75% margin:2em|auto">
      <div class="grid-cols:2 h:100%">
        <div class="p:2em">
          <div class="font:3em mt:1.5em font-weight:900">Project 3 | Pokémon</div>
          <div class="font:1.2em mt:1em line-height:2em font-weight:500 f:#aaa">
            融入線上對戰，與全球訓練家一較高下！，<br />
            感受激烈的戰鬥，將你的寶可夢訓練到巔峰！<br />
            絕妙的BGM伴隨著每場戰鬥，帶你進入寶可夢的音樂世界。<br />
            攜手夥伴，征服世界各地的挑戰，將你的冒險完美結束！
          </div>
          <div class="mt:8em flex gap:8px">
            <n-button class="p:1em|2em font:2em font-weight:500" type="primary">
              <n-icon class="mr:8px" size="32px">
                <PokemonBallIcon />
              </n-icon>
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
          :class="`bg:url('${HomeImage}') height:600px background-size:150% bg:no-repeat background-position:0%|50%`"
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
