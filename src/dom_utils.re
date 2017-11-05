module Event = {
  type mouseDownEventType;
  [@bs.get] external code : mouseDownEventType => string = "";
  [@bs.get] external keyCode : mouseDownEventType => int = "";
};

module Document = {
  /* hardcoded since we're only using this one */
  [@bs.val] [@bs.scope "document"]
  external addEventListener :
    (string, Event.mouseDownEventType => unit) => unit =
    "";
};
