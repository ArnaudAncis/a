require 'MetaData'
require 'Html'
require 'Code'
require 'Cpp'
require 'Upload'
require 'Html'
require 'Environment'
require 'pathname'
require 'fileutils'
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

  # Check for existence directories
  [ 'fractals', 'fractals/fractals', 'fractals/fractals/solutions' ].each do |dir|
    abort "Directory #{dir} not found" unless Dir.exist? dir
  end

  img_actions = Dir[ 'fractals/fractals/solutions/ex*-solution.cpp' ].map do |file|
    cpp_path = Pathname.new(file)
    exe_path = cpp_path.basename.sub_ext('.exe')
    bmp_path = Pathname.new('output.bmp')
    png_path = cpp_path.basename.sub_ext('.png')
    action_name = png_path.to_s
    
    action(action_name) do
      aux_files = Dir[ 'fractals/fractals/*.cpp' ]
      dir_path = Pathname.new('fractals/fractals').expand_path

      command = "cl -I\"#{dir_path.to_s}\" -O2 -EHsc -Fe#{exe_path.to_s} #{aux_files.join(' ')} #{cpp_path.to_s}"
      puts "Executing #{command}"
      Environment.execute(command)

      puts "Removing old #{bmp_path.to_s}"
      if bmp_path.file?
      then FileUtils.rm(bmp_path)
      end

      puts "Executing #{exe_path.to_s}"
      Environment.execute(exe_path)

      abort "Expected #{exe_path.to_s} to produce output.bmp" unless File.exist? 'output.bmp'

      Image.convert(bmp_path, png_path, trim: false, density: nil, quality: nil)
    end

    action_name
  end
  

  group_action(:img, img_actions)

  html_template('assignment', context: Context.new, group_name: 'html')
  
  uploadable('assignment.html')
  uploadable_globs( 'ex*-solution.png' )
  upload_action

  group_action(:full, [:img, :html, :upload])
end
