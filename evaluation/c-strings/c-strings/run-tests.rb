require 'pathname'
require 'open3'

class RunError < StandardError; end

def run(command)
  Open3.popen3(command) do |stdin, stdout, stderr, wait_thr|
    status = wait_thr.value

    if status != 0
      raise RunError
    else
      stdout.read
    end
  end
end  

def compile(*files)
  run("cl -Fe#{} #{files.join(' ')}")
end


def main
  puts Pathname.new('.').expand_path
end


main
