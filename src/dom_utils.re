module Event = {
  type mouseDownEventType;
  external code : mouseDownEventType => string = "" [@@bs.get];
  external keyCode : mouseDownEventType => int = "" [@@bs.get];
};

module Document = {
  /* hardcoded since we're only using this one */
  external addEventListener :
    string => (Event.mouseDownEventType => unit) => unit =
    "" [@@bs.val] [@@bs.scope "document"];
};
