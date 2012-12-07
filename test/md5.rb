assert('MD5 Hash for "ruby"') do
  MD5.md5_hex('ruby') == '58e53d1324eef6265fdb97b08ed9aadf'
end

assert('MD5 Hash for old example') do
  MD5::md5_hex('お前はどこのワカメじゃ') == "43820f48a8506c8e2fae6f8558971920"
end
