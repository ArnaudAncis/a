require 'MetaData'
require 'Html'
require 'Code'
require 'Cpp'
require 'Upload'
require 'Html'
require 'Environment'
require 'pathname'
require 'fileutils'
require 'find'
require '../shared.rb'

module Quiz
  extend Html::Generation::Quiz
end


class Context < SharedContext
  include Contracts::TypeChecking
  include Html::Generation
end



meta_object do
  extend MetaData::Actions
  extend Html::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory + Pathname.pwd.basename.to_s
  end

  exe_path = Pathname.new('manip.exe')

  action(:compile, description: 'Compiles image-manipulation project') do
    dir_path = Pathname.new('image-manipulation/image-manipulation').expand_path
    cpp_files = Find.find('.').select do |file|
      file.end_with? '.cpp'
    end
    
    command = "cl -I\"#{dir_path.to_s}\" -O2 -EHsc -Fe#{exe_path.to_s} #{cpp_files.join(' ')}"
    puts `#{command}`
  end

  action('sample.bmp', description: 'Converts sample.jpg to sample.bmp') do
    puts `convert sample.jpg sample.bmp`
  end

  image_action_names = { 'grayscale' => 'grayscale',
                         'blur5' => 'blur 5',
                         'blur2' => 'blur 2',
                         'invert' => 'invert',
                         'hflip' => 'hflip',
                         'vflip' => 'vflip',
                         'red' => 'red',
                         'green' => 'green',
                         'blue' => 'blue',
                         'mosaic5' => 'mosaic 5' }.to_a.map do |basename, options|
    filename = "#{basename}.bmp"
    action_name = filename
    
    action(action_name) do
      abort "Missing sample.bmp; build it first" unless File.exist? 'sample.bmp'
      abort "Missing #{exe_path}; build it first" unless exe_path.file?
     
      command = "#{exe_path.to_s} sample.bmp #{filename} #{options}"
      puts `#{command}`
    end

    action_name
  end

  group_action(:img, [:compile, 'sample.bmp'] + image_action_names)
  
  html_template('assignment', context: Context.new, group_name: 'html')
  
  uploadable('assignment.html')
  uploadable_globs( '*.bmp' )
  upload_action

  group_action(:full, [:img, :html, :upload])
end
