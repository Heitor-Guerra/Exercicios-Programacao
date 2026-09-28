local function main()
  print("Digite uma sequência:");
  local str = "";
  str = io.read("l");

  local convertTable = {
    ["("] = ")",
    ["["] = "]",
    ["{"] = "}",
  }
  local charStack = {};

  for c in string.gmatch(str, ".") do
    for key, value in pairs(convertTable) do
      if c == key then
        table.insert(charStack, convertTable[c]);
      elseif c == value and c ~= table.remove(charStack) then
        print("Brackets do not match");
        return;
      end
    end
  end

  if #charStack == 0 then
    print("The Brackets Match")
  else
    print("Brackets do not match")
  end
end

main();
