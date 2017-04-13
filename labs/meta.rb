require 'MetaData2'
require 'Upload2'
require 'Shortcuts'


meta_object do
  extend MetaData2
  extend Upload2::Actions
  extend Shortcuts::Actions


  inherit_remote_directory 'labs'

  quick_recursive_all

  register_transfer( Pathname.new('pvm.css').expand_path,
                     Pathname.new('/var/www/courses/shared/pvm.css') )
end
