<template>
    <a-sub-menu :key="menuInfo.key">
        <template #title>{{ menuInfo.title}}</template>
        <template v-for="item in menuInfo.children">
          <a-menu-item v-if="!item.children" :key="item.key">
            {{ item.title  }}
          </a-menu-item>
          <PopSubMenu v-else :key="item.key" :menuInfo="item" />
        </template>
    </a-sub-menu>
</template>

<script>
export default {
    name: 'PopSubMenu',
    props: ['menuInfo'],
}
</script>
