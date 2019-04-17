open Dom_utils;

CSS_utils.requireCSS("./index.css");

let init = _ =>
  Document.addEventListener("keydown", evt =>
    ReactDOMRe.renderToElementWithId(<App evt />, "root")
  );

init();

ReactDOMRe.renderToElementWithId(<App />, "root");
