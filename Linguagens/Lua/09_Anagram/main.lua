---@param str1 string
---@param str2 string
--- @return boolean
local function areAnangrams(str1, str2)
  if str1:len() ~= str2:len() then return false end

  --- @type table
  local chars1 = {}
  local chars2 = {}
  for c in str1:gmatch(".") do chars1[c] = (chars1[c] or 0) + 1 end
  for c in str2:gmatch(".") do chars2[c] = (chars2[c] or 0) + 1 end

  for key, value in pairs(chars1) do
    if value ~= chars2[key] then return false end
  end
  return true
end

local function main()
  print("Insert the target word.")
  --- @type string
  local target = io.read("l"):lower()
  local targetPattern = "[^" .. target .. "]"

  print("Insert the number of candidates followed by them")
  --- @type number
  local numCandidates = io.read("n")
  --- @type table
  local candidates = {}

  local trash = io.read()

  for i = 1, numCandidates, 1 do
    candidates[i] = io.read("l"):lower()
  end

  local haveAnagram = false
  --- @param index number
  --- @param value string
  for index, value in ipairs(candidates) do
    if areAnangrams(target, value) then
      print(index .. " item: " .. value .. " is an anagram.")
      haveAnagram = true
    end
  end
  if not haveAnagram then
    print("Doesn't have an anagram.");
  end
end

main()
