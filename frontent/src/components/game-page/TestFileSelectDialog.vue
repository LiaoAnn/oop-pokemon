<template>
  <n-layout vertical>
    <n-layout-content>
      <n-upload v-model:file-list="fileList" accept="text/plain" @update:file-list="updateFileList">
        <n-button>上傳文件</n-button>
      </n-upload>
    </n-layout-content>

    <n-layout-content>
      <n-space justify="end">
        <n-button type="primary" :disabled="fileList.length === 0" @click="readFileContent">
          提交
        </n-button>
      </n-space>
    </n-layout-content>
  </n-layout>
</template>

<script setup lang="ts">
import type { UploadFileInfo } from 'naive-ui';
import { NButton, NLayout, NLayoutContent, NSpace, NUpload } from 'naive-ui';
import { ref } from 'vue';

//#region Props and Emits
type SubmitValue = {
  Monster: string;
  Move: string;
  GameData: string;
  Case: string;
};

const emits = defineEmits({
  'update:show': (value: boolean) => true,
  submit: (value: SubmitValue) => true
});
//#endregion

const fileList = ref<UploadFileInfo[]>([]);

const updateFileList = () => {
  if (fileList.value.length > 1) fileList.value.shift();
};

const readFileContent = async () => {
  const file = fileList.value[0].file!;
  const content = (await file.text()).split('\n');
  const [Monster, Move, GameData, _] = content;
  emits('submit', { Monster, Move, GameData, Case: file.name });
};
</script>
