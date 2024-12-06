local syntax = require "core.syntax"

syntax.add {
  files = { "%.wren$" },
  comment = "//",
  patterns = {
    { pattern = "//.-\n",                 type = "comment"  },
    { pattern = { "/%*", "%*/" },         type = "comment"  },
    { pattern = { '"', '"', '\\' },       type = "string"   },
    { pattern = { "'", "'", '\\' },       type = "string"   },
    { pattern = "-?%.?%d+",               type = "number"   },
    { pattern = "%.%.%.?",                type = "operator" },
    { pattern = "[<>!=]=",                type = "operator" },
    { pattern = "[%+%-=/%*%^%%<>!~|&?:]", type = "operator" },
    { pattern = "[%a_][%w_]*%s*%f[(\"{]", type = "function" },
    { pattern = "[%a_][%w_]*",            type = "symbol"   },
  },
  symbols = {
    ["break"]     = "keyword",
    ["class"]     = "keyword",
    ["construct"] = "keyword",
    ["else"]      = "keyword",
    ["false"]     = "keyword",
    ["for"]       = "keyword",
    ["foreign"]   = "keyword",
    ["if"]        = "keyword",
    ["import"]    = "keyword",
    ["in"]        = "keyword",
    ["is"]        = "keyword",
    ["null"]      = "keyword",
    ["return"]    = "keyword",
    ["static"]    = "keyword",
    ["super"]     = "keyword",
    ["this"]      = "keyword",
    ["true"]      = "keyword",
    ["var"]       = "keyword",
    ["while"]     = "keyword",
    ["this"]      = "keyword2",
    ["true"]      = "literal",
    ["false"]     = "literal",
    ["null"]      = "literal",
  },
}