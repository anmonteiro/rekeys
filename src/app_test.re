open Jest;

open Dom_utils;

external toMouseDownEvent : Js.t({..}) => Event.mouseDownEventType =
  "%identity";

Js.log(toMouseDownEvent({"keyCode": "foo", "code": 42}));

describe(
  "Expect",
  (_) => {
    test("addition", () => Expect.(expect(3 + 4) |> toBe(7)));
    test("addition", () => Expect.(expect(1 + 4) |> toBe(7)))
  }
);
