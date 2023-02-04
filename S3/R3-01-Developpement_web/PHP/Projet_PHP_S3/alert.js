<article id="alert_container"></article>
<style>
    #alert_container {
        width: 500px;
        position: fixed;
        top: 0;
        right: 0;
    }
    .error {
        background-color: rgba(215, 116, 116, 0.93);
        color: #4d0f0f;
    }
    .info {
        background-color: rgba(116, 136, 215, 0.93);
        color: #0f234d;
    }
    .warning {
        background-color: rgba(215, 195, 116, 0.93);
        color: #4d480f;
    }
    .success {
        background-color: rgba(126, 215, 116, 0.93);
        color: #0f4d10;
    }

</style>
<script>
    var alertContainer = document.getElementById("alert_container");

    alert = false;

    function alertMessage (message, gravity="info") {
        if (alert == true) {
            alert = false;
            hideCurrentAlert();
        }

        alert = true;
        var div = document.createElement("div")
        let span = document.createElement("span")
        let text = document.createElement("p")
        span.classList.add("material-symbols-outlined");
        span.append('error');
        text.append(message);
        div.id = "alert-message"
        div.classList.add("alert-message",gravity);
        div.append(span, text)
        alertContainer.append(div);

        setTimeout("let div = document.getElementById('alert-message'); div.style.opacity = '1'", 0);
        setTimeout("hideCurrentAlert()", 4000);
    }

    function hideCurrentAlert() {
        let alertMessage = document.getElementById("alert-message");
        alertMessage.style.opacity = "0";
        setTimeout("alertContainer.removeChild(alertMessage);", 500);
    }
</script>
