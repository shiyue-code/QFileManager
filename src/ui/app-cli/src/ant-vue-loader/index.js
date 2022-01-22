import {
    Button, Image, Menu, Layout, Breadcrumb, Row, Col, Dropdown
} from 'ant-design-vue';

export default  {
    install: (app) => {
        app.use(Dropdown)
        app.use(Button)
        app.use(Image)
        app.use(Layout)
        app.use(Menu)   
        app.use(Breadcrumb)
        app.use(Row)
        app.use(Col)
    }
}