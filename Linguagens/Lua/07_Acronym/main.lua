local function main()
  print("Enter the phrase")
  --- @type string
  local str = io.read("l") .. " "
  str = str:gsub("%p", "")

  --- @type string
  local output = ""
  for word in str:gmatch("%a+[%s%-]") do
    --- @type string
    output = output .. word:sub(1, 1)
  end
  print(output:upper())
end
main()
