<template>
  <n-layout>
    <SiteHeader />
    <router-view />
    <SiteFooter />
  </n-layout>
</template>

<script setup lang="ts">
import { NLayout } from 'naive-ui';

import SiteFooter from '@/components/SiteFooter.vue';
import SiteHeader from '@/components/SiteHeader.vue';
</script>
