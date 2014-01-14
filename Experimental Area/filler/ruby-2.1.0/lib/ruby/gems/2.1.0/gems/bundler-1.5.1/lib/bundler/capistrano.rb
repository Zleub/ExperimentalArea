# Capistrano task for Bundler.
#
# Just add "require 'bundler/capistrano'" in your Capistrano deploy.rb, and
# Bundler will be activated after each new deployment.
require 'bundler/deployment'
require 'capistrano/version'

if defined?(Capistrano::Version) && Gem::Version.new(Capistrano::Version).release >= Gem::Version.new("3.0")
  raise "For Capistrano 3.x integration, please use http://github.com/capistrano/bundler"
end

Capistrano::Configuration.instance(:must_exist).load do
  before "deploy:finalize_update", "bundle:install"
  Bundler::Deployment.define_task(self, :task, :except => { :no_release => true })
  set :rake, lambda { "#{fetch(:bundle_cmd, "bundle")} exec rake" }
end
