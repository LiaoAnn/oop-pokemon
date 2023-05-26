<template>
  <n-config-provider>
    <n-dialog-provider>
      <n-loading-bar-provider>
        <n-message-provider>
          <n-notification-provider>
            <router-view />
          </n-notification-provider>
        </n-message-provider>
      </n-loading-bar-provider>
    </n-dialog-provider>
  </n-config-provider>
</template>

<script setup lang="ts">
import '@master/css';

import {
  NConfigProvider,
  NDialogProvider,
  NLoadingBarProvider,
  NMessageProvider,
  NNotificationProvider
} from 'naive-ui';
</script>
