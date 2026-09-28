--- @type table
local conversion = {
  ["M"] = 1000,
  ["D"] = 500,
  ["C"] = 100,
  ["L"] = 50,
  ["X"] = 10,
  ["V"] = 5,
  ["I"] = 1,
}

--- @param str string
--- @return boolean
local function isValidRoman(str)
  return str:len() > 0 and str:match("^[M,D,C,L,X]") ~= nil
end

--- @param str string
--- @return number
local function getValue(str)
  local num = 0;
  for i = 1, str:len(), 1 do
    local temp = conversion[str:sub(i, i)]
    local temp2 = conversion[str:sub(i + 1, i + 1)]
    if temp2 and temp2 > temp then
      num = num - temp
    else
      num = num + temp
    end
  end
  return num
end




local function main()
  print("Insert the Roman number.")
  --- @type string
  local str = io.read("l")
  str = str:upper()
  --- @type number
  local num = 0

  if isValidRoman(str) then
    print(getValue(str))
  else
    print("Not valid")
  end
end


main()
