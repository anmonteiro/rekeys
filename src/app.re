open Dom_utils;

CSS_utils.requireCSS "./app.css";

let str = ReasonReact.stringToElement;

type keyInfo = Js.t {. code : int, name : string};

module KeyInfo = {
  let component = ReasonReact.statelessComponent "KeyInfo";
  let make keyInfo::(k: option keyInfo) _children => {
    ...component,
    render: fun _self =>
      <div className="key-info">
        (
          switch k {
          | Some info =>
            ReasonReact.arrayToElement [|
              <div key="1" className="key-code">
                (str (string_of_int info##code))
              </div>,
              <div key="2" className="key">
                <div className="keycap"> (str info##name) </div>
              </div>
            |]
          | None => <div className="hint"> (str "C'mon, press a key!") </div>
          }
        )
      </div>
  };
};

let component = ReasonReact.statelessComponent "App";

let make keyInfo::k=? _children => {
  ...component,
  render: fun _ =>
    <div className="App">
      <div className="App-header">
        <h2> (str "ReKeys") </h2>
        <h3> (str "Find out JavaScript event keycodes by pressing keys") </h3>
      </div>
      <div className="App-content"> <KeyInfo keyInfo=k /> </div>
      <div className="App-footer">
        <p>
          (str "Made with ")
          <a href="/" className="reimg">
            <img
              href="https://reasonml.github.io/"
              src="data:image/png;base64,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"
            />
          </a>
          (str " by ")
          <a href="https://twitter.com/anmonteiro90">
            (str "@anmonteiro90")
          </a>
        </p>
      </div>
    </div>
};

let keyInfoOfEvent: Event.mouseDownEventType => keyInfo =
  fun e => {
    let code =
      switch (e |> Event.code |> Js.String.splitByRe [%re "/(?=[A-Z0-9])/"]) {
      | [|x|] => x
      | [|"Key", x|]
      | [|"Digit", x|] => x
      | [|"F" as x, y|] => x ^ y
      | [|_, _|] as arr => String.concat " " (Array.to_list arr)
      | _ => "Unknown"
      };
    {"code": Event.keyCode e, "name": code}
  };
