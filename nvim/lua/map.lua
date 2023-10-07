
-- /lua/map.lua

local keymap = vim.keymap

keymap.set('n', '<C-a>', 'gg<S-v>G')
-- Toggle NeoTree sidebar
keymap.set('n', '<leader>e', ':NvimTreeToggle<cr>')

-- Moving around windows using s + h,j,k,l
keymap.set('n', 'sh', '<C-w>h')
keymap.set('n', 'sj', '<C-w>j')
keymap.set('n', 'sk', '<C-w>k')
keymap.set('n', 'sl', '<C-w>l')

-- Split windows
keymap.set('n', 'ss', ':split<cr><C-w>w')
keymap.set('n', 'sv', ':vsplit<cr><C-w>w')

-- Next/Prev tab page
keymap.set('n', '<leader>n', ':BufferLineCycleNext<CR>')
keymap.set('n', '<leader>b', ':BufferLineCyclePrev<CR>')

-- Close all tabs
keymap.set('n', '<leader>ta', [[:tabedit<cr>:BufferLineCloseLeft<cr>:BufferLineCloseRight<cr>]])
-- Keep current tab and close the others
keymap.set('n', '<leader>to', [[:BufferLineCloseLeft<cr>:BufferLineCloseRight<cr>]])

-- Save file
keymap.set('n', '<C-s>', ':w<cr>')
-- do somthing else

-- Move lines and group lines left, right
keymap.set('v', '>', '>gv')
keymap.set('v', '<', '<gv')

-- Move lines and group lines up, down
keymap.set('n', 'K', ':m .-2<cr>')
keymap.set('n', 'J', ':m .+1<cr>')

keymap.set('v', 'K', ":m '<-2<CR>gv=gv")
keymap.set('v', 'J', ":m '>+1<CR>gv=gv")

-- Find file in NvimTree
keymap.set('n', '@', ':NvimTreeFindFile<cr>')

-- Duplicate line
keymap.set('n', '<C-d>', 'yyp')