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
    dir_path = Pathname.new('image-manipulation/solution').expand_path
    cpp_files = Find.find('image-manipulation/solution').select do |file|
      file.end_with? '.cpp'
    end
    
    command = "cl -I\"#{dir_path.to_s}\" -O2 -EHsc -Fe#{exe_path.to_s} #{cpp_files.join(' ')}"
    puts "Executing #{command}"
    puts `#{command}`
  end

  action('sample.bmp', description: 'Converts sample.jpg to sample.bmp') do
    puts `convert sample.jpg sample.bmp`
  end

  bmp_actions = []
  jpg_actions = []

  { 'grayscale' => 'grayscale',
    'blur5' => 'blur 5',
    'blur10' => 'blur 10',
    'invert' => 'invert',
    'hflip' => 'hflip',
    'vflip' => 'vflip',
    'red' => 'red',
    'green' => 'green',
    'blue' => 'blue',
    'mosaic20' => 'mosaic 20',
    'mosaic30' => 'mosaic 30'
  }.to_a.each do |basename, options|
    bmp_name = "#{basename}.bmp"
    jpg_name = "#{basename}.jpg"
    
    action(bmp_name) do
      abort "Missing sample.bmp; build it first" unless File.exist? 'sample.bmp'
      abort "Missing #{exe_path}; build it first" unless exe_path.file?

      puts "Generating #{bmp_name}"
      command = "#{exe_path.to_s} sample.bmp #{bmp_name} #{options}"
      puts `#{command}`
    end

    action(jpg_name) do
      puts "Converting #{bmp_name} to #{jpg_name}"
      command = "convert #{bmp_name} #{jpg_name}"
      puts `#{command}`
    end

    bmp_actions << bmp_name
    jpg_actions << jpg_name
  end.flatten

  group_action(:bmp, bmp_actions)
  group_action(:jpg, jpg_actions)
  group_action(:img, ['sample.bmp', :bmp, :jpg])
  
  html_template('assignment', context: Context.new, group_name: 'html')
  
  uploadable('assignment.html')
  uploadable_globs( '*.jpg' )
  uploadable_globs( 'sample.bmp' )
  upload_action

  group_action(:full, [:img, :html, :upload])
end
