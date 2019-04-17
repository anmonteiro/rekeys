open Dom_utils;

CSS_utils.requireCSS("./app.css");

module KeyInfo = {
  type keyInfo = {
    code: int,
    name: string,
  };

  let keyInfoOfEvent = e => {
    let code =
      switch (e |> Event.code |> Js.String.splitByRe([%re "/(?=[A-Z0-9])/"])) {
      | [|Some(x)|] => x
      | [|Some("Key"), Some(x)|]
      | [|Some("Digit"), Some(x)|] => x
      | [|Some("F" as x), Some(y)|] => x ++ y
      | [|_, _|] as arr =>
        String.concat(" ", Array.to_list(arr)->Belt.List.keepMap(x => x))
      | _ => "Unknown"
      };
    {code: Event.keyCode(e), name: code};
  };

  [@react.component]
  let make = (~evt=?) =>
    <div className="key-info">
      {switch (evt) {
       | Some(evt) =>
         let {code, name} = keyInfoOfEvent(evt);
         ReasonReact.array([|
           <div key="1" className="key-code">
             {React.string(string_of_int(code))}
           </div>,
           <div key="2" className="key">
             <div className="keycap"> {React.string(name)} </div>
           </div>,
         |]);
       | None =>
         <div className="hint"> {React.string("C'mon, press a key!")} </div>
       }}
    </div>;
};

[@react.component]
let make = (~evt=?) => {
  <div className="App">
    <div className="App-header">
      <h2> {React.string("ReKeys")} </h2>
      <h3>
        {React.string("Find out JavaScript event keycodes by pressing keys")}
      </h3>
    </div>
    <div className="App-content"> <KeyInfo ?evt /> </div>
    <div className="App-footer">
      <p>
        {React.string("Made with ")}
        <a href="https://reasonml.github.io/" className="reimg">
          <img src=Logo.logo />
        </a>
        {React.string(" by ")}
        <a href="https://twitter.com/_anmonteiro">
          {React.string("@_anmonteiro")}
        </a>
      </p>
    </div>
  </div>;
};
