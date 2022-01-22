<template>
    <a-menu
      :selectable=false
      mode="inline"
    >
      <template v-for="item in menuInfoList">
        <a-menu-item v-if="!item.children" :key="item.key">
          <span>{{ item.title }}</span>
        </a-menu-item>
        <PopSubMenu v-else :menuInfo="item" :key="item.key" />
      </template>
    </a-menu>
</template>

<script>
import PopSubMenu from './PopSubMenu.vue'
export default {
  name: 'PopMenu',
  props: ['menuInfoList'],
  setup() {
    return {
        collapsed: true
    };
  },
  components: {
    PopSubMenu,
  },
}
</script>
