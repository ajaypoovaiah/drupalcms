<?php

/**
 * @file course_relationships.course.inc
 * Holds course module specific hooks.
 */

/**
 * Outline callback for Course module.
 */
function course_relationships_outline($node, $user) {
  drupal_goto("node/$node->nid");
}

/**
 * Implements hook_course_handlers().
 */
function course_relationships_course_handlers() {
  return array(
    /*
    'settings' => array(
      'relationships' => array(
        'name' => t('Relationships'),
        'description' => t('Configure course relationsips.'),
        'callback' => 'course_relationships_settings_form',
        'file' => 'course_relationships.course.inc',
        'file path' => drupal_get_path('module', 'course_relationships'),
      ),
    ),
    */
    // Set an outline for now only so that we have something to select on the
    // parent. We can no longer check $node->course['lms'] == 'relationships'.
    'outline' => array(
      'relationships' => array(
        'name' => t('Relationships'),
        'description' => t('A parent course displaying a tree of children.'),
        // For now display the stock outline.
        'callback' => 'course_relationships_outline',
        'file' => 'course_relationships.course.inc',
        'file path' => drupal_get_path('module', 'course_relationships'),
      ),
    ),
    'object' => array(
      'course' => array(
        'name' => 'Course',
        'description' => 'Add a course to this course.',
        'class' => 'CourseObjectCourse',
      ),
    ),
  );
}

/**
 * Course settings handler callback.
 */
function course_relationships_settings_form() {
  $form = array();

  return system_settings_form($form);
}
