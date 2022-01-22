<template>
  <a-dropdown :trigger="['contextmenu']">
    <div       :style="{
        textAlign: 'center',
        background: '#f7f7f7',
        height: '100%',
        lineHeight: '100%',
        color: '#777',
      }">
      <a-layout class="layout">
        <a-layout-header class="windowTitle">
          <a-row>
          <a-button>
            <template #icon><FolderOpenTwoTone /></template>
          </a-button>
          <a-col flex="auto">
            <a-row  type="flex" justify="end">
            <a-button type='text' class="windowsButton">
              <template #icon><MinIcon /></template>
            </a-button>
            <a-button type='text' class="windowsButton">
              <template #icon><MaxIcon /></template>
            </a-button>
            <a-button type='text' class="windowsClose">
              <template #icon><CloseIcon /></template>
            </a-button>
            </a-row>
          </a-col>
          </a-row>

        </a-layout-header>
        <a-layout-content style="padding: 0 0px">
          <div :style="{ background: '#fff', padding: '4px', height:'100%'}">Content</div>
        </a-layout-content>
        <a-layout-footer style="{text-align: center, lineHeight: '35px' }">
          Ant Design ©2018 Created by Ant UED
        </a-layout-footer>
      </a-layout>
    </div>
    <template #overlay>
      <pop-menu :menuInfoList="menuInfo"/>
    </template>


  </a-dropdown>
</template>

<script>
import {
    FolderOpenTwoTone,
  } from '@ant-design/icons-vue';
import MaxIcon from './Icon/MaxIcon.vue';
import CloseIcon from './Icon/CloseIcon.vue';
import MinIcon from './Icon/MinIcon.vue';
import PopMenu from './PopMenu.vue';

export default {
  name: 'MainWindow',
  props: {
    msg: String
  },
  components: {
    FolderOpenTwoTone,
    MaxIcon,
    CloseIcon,
    MinIcon,
    PopMenu
  },
  setup() {
    return {
      menuInfo: [
        {
          key: '1',
          title: 'Option 1',
        },
                {
          key: '2',
          title: 'Navigation 2',
          children: [
            {
              key: '2.1',
              title: 'Navigation 3',
              children: [{ key: '2.1.1', title: 'Option 2.1.1' },{ key: '2.1.2', title: 'Option 2.1.2' }],
            },
          ],
        },
                {
          key: '3',
          title: 'Option 3',
        },

      ]
    };
  },
}
</script>
<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.windowTitle {
  height: 32px;
  padding: 0 0 0 0;
}
.layout {
  height: 100%;
}
.windowsButton:hover  {
  background: rgb(2, 19, 75);
}
.windowsClose:hover  {
  background: red;
  opacity: 80%;
}

.windowsClose:active  {
  background: red;
  opacity: 100%;
}

.rightTitle {
  float:right;
  width: 50%;
}
</style>
