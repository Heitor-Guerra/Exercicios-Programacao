local Complex = require("complexNumber")

local function main()
  local a = Complex:new(10, 20);
  local b = Complex:new(5, 10);
  print(a / b);
end

main()
