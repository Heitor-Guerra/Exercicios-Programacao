--- @type table
local ZERO_TO_TWENTY = {
  [0] = "zero",
  [1] = "one",
  [2] = "two",
  [3] = "three",
  [4] = "four",
  [5] = "five",
  [6] = "six",
  [7] = "seven",
  [8] = "eight",
  [9] = "nine",
  [10] = "ten",
  [11] = "eleven",
  [12] = "twelve",
  [13] = "thirteen",
  [14] = "fourteen",
  [15] = "fifteen",
  [16] = "sixteen",
  [17] = "seventeen",
  [18] = "eighteen",
  [19] = "nineteen",
}

--- @type table
local TENS = {
  [2] = "twenty",
  [3] = "thirty",
  [4] = "forty",
  [5] = "fifty",
  [6] = "sixty",
  [7] = "seventy",
  [8] = "eighty",
  [9] = "ninety"
}

--- @type table
local BASES = {
  [1] = "hundred",
  [2] = "thousand",
  [3] = "million",
  [4] = "billion"
}


local function main()
  print("Enter a number (to the billions).")
  --- @type number
  local num = io.read("n");
  if num == 0 then
    print(ZERO_TO_TWENTY[0])
    return
  end

  --- @type string
  local output = ""
  local magnitude = 1

  while num > 0 do
    if magnitude ~= 1 and num % 1000 ~= 0 then
      output = BASES[magnitude] .. " " .. output
    end

    local temp = num % 100
    num = num // 100
    if temp < 20 and temp ~= 0 then
      output = ZERO_TO_TWENTY[temp] .. " " .. output
    elseif temp ~= 0 then
      local ten = temp // 10;
      local unit = temp % 10;
      if unit == 0 then
        output = TENS[ten] .. " " .. output
      else
        output = TENS[ten] .. "-" .. ZERO_TO_TWENTY[unit] .. " " .. output
      end
    end
    if num == 0 then
      break
    end

    local hundred = num % 10
    num = num // 10
    if hundred ~= 0 then
      output = ZERO_TO_TWENTY[hundred] .. " " .. BASES[1] .. " " .. output
    end

    magnitude = magnitude + 1
  end
  print(output)
end

main()
