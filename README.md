<div style="line-height:1.7;color:#000000;font-size:14px;font-family:Arial">
    <p>
        easypush
        <br>
        ========
    </p>
    <p>
        this is a tranplant project of icomet, which you can find at "
        <a href="https://github.com/ideawu/icomet" target="_blank">
            https://github.com/ideawu/icomet
        </a>
        ".
    </p>
    <p>
        <br>
        I wish this can be easy for vc developer on Windows platforms to get started
        with icomet.
    </p>
    <p>
        <br>
        faq:
    </p>
    <p>
        <br>
        1. start easypush server
    </p>
    <p>
        ./easypush.exe icomet.conf
    </p>
    <p>
        explain:
    </p>
    <p>
        please copy icomet.conf to the directory where easypush.exe is
    </p>
    <p>
        2. subscribe a channel
    </p>
    <p>
        by curl:
    </p>
    <p>
        curl -v "
        <a href="http://127.0.0.1:8100/sub?cname=12" target="_blank">
            http://127.0.0.1:8100/sub?cname=12
        </a>
        "
    </p>
    <p>
        by browser:
    </p>
    <p>
        <a href="http://127.0.0.1:8100/sub?cname=12" target="_blank">
            http://127.0.0.1:8100/sub?cname=12
        </a>
    </p>
    <p>
        explain:
    </p>
    <p>
        cname : channel name
    </p>
    <p>
        3. publish a push message for a channel
    </p>
    <p>
        by curl:
    </p>
    <p>
        curl -v "
        <a href="http://127.0.0.1:8000/push?cname=12&content=hi" target="_blank">
            http://127.0.0.1:8000/push?cname=12&content=hi
        </a>
        "
    </p>
    <p>
        by browser:
    </p>
    <p>
        <a href="http://127.0.0.1:8000/push?cname=12&content=hi" target="_blank">
            http://127.0.0.1:8000/push?cname=12&content=hi
        </a>
    </p>
    <p>
        explain:
    </p>
    <p>
        content : the message content to push(the message that you want your subscribers
        to receive)
    </p>
    <p>
        4. finally
    </p>
    <p>
        finally, best reagrds to developers of icomet
    </p>
    <p>
        <br>
    </p>
</div>
<br>
<br>

