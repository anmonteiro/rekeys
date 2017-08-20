open Dom_utils;

CSS_utils.requireCSS "./index.css";

external register_service_worker : unit => unit =
  "" [@@bs.module "./registerServiceWorker"];

let init _ =>
  Document.addEventListener
    "keydown"
    (
      fun e =>
        ReactDOMRe.renderToElementWithId
          <App keyInfo=(App.keyInfoOfEvent e) /> "root"
    );

init ();

ReactDOMRe.renderToElementWithId <App /> "root";
