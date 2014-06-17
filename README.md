easypush
========

this is a tranplant project of icomet, which you can find at "https://github.com/ideawu/icomet"

I wish this can be easy for vc developer on Windows platforms to get started with icomet

faq:

1. start easypush server
./easypush.exe icomet.conf

explain:
please copy icomet.conf to the directory where easypush.exe is

2.subscribe a channel
by curl:
curl -v "http://127.0.0.1:8100/sub?cname=12"

by browser:
http://127.0.0.1:8100/sub?cname=12

explain:
cname : channel name

3.publish a push message for a channel
by curl:
curl -v "http://127.0.0.1:8000/push?cname=12&content=hi"

by browser:
http://127.0.0.1:8000/push?cname=12&content=hi

explain:
content : the message content to push(the message that you want your subscribers to receive)

finally, best reagrds to developers of icomet
