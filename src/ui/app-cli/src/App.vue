<template>
  <MainWindow />
</template>

<script>
import MainWindow from './components/MainWindow.vue'

export default {
  name: 'App',
  components: {
    MainWindow
  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin: 0 0 0 0;
  height: 100%;
}
</style>
