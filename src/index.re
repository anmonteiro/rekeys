open Dom_utils;

CSS_utils.requireCSS "./index.css";

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
