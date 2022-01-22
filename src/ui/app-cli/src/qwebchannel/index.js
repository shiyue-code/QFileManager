import { QWebChannel } from "./qwebchannel"



export default function InitQWebChannel() {
    window.onload = function() {
        if(Object.prototype.hasOwnProperty.call(window, "qt")) 
        {
            new QWebChannel(
                window.qt.webChannelTransport, (channel)=> {
                  window.qHandle = channel.objects.qHandle
                  alert(window.qHandle)
                  window.qHandle.send({
                    userid: 100
                  })
                }
            )
        }
    }
}