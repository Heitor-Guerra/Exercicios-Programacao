local function main()
  print("Insert the sentence.")
  --- @type string
  local str = io.read("l")

  print("Insert the size of the sub-sentences")
  --- @type number
  local n = io.read("n")

  if n > str:len() then
    print("N is bigger than the sentence.");
  end

  for i = 1, str:len() - n + 1, 1 do
    --- @type string
    local substr = str:sub(i, i + n - 1);
    print(substr);
  end
end

main()
