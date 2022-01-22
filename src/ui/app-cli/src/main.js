import { createApp } from 'vue'
import App from './App.vue'
import loaderAntVue from './ant-vue-loader/index'
import InitWebChannel from './qwebchannel/index'

InitWebChannel()
createApp(App).use(loaderAntVue).mount('#app')
